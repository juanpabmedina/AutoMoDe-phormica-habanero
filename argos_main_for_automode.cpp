
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/entity/entity.h>
#include <argos3/core/simulator/entity/controllable_entity.h>
#include <argos3/core/utility/plugins/dynamic_loading.h>
#include <argos3/core/simulator/query_plugins.h>
#include <argos3/core/simulator/argos_command_line_arg_parser.h>

#include "/home/aligot/Desktop/E-puck/argos3-aligot/controllers/AutoMoDe/finite_state_machine/AutoMoDeFiniteStateMachine.h"
#include "/home/aligot/Desktop/E-puck/argos3-aligot/controllers/AutoMoDe/finite_state_machine/AutoMoDeFsmBuilder.h"
#include "/home/aligot/Desktop/E-puck/argos3-aligot/controllers/AutoMoDe/AutoMoDeController.h"

using namespace argos;

/**
 * @brief The standard main() function to run the ARGoS simulator.
 *
 * This main() function provides the basic logic to run the ARGoS
 * simulator: parses the command line, loads the experiment, runs the
 * simulation and disposes all the data.
 *
 * @param n_argc the number of command line arguments given at the shell.
 * @param ppch_argv the actual command line arguments.
 * @return 0 if everything OK; 1 in case of errors.
 */
int main(int n_argc, char** ppch_argv) {
	
	bool bReadableFSM = false;
	bool bHistoryFSM = false;
	std::vector<std::string> vecConfigFsm;
	bool bFsmControllerFound = false;
	
	try {
		
		/* Cutting off the FSM configuration from the command line */
		int nCurrentArgument = 1;
		while(!bFsmControllerFound) {
			if(strcmp(ppch_argv[nCurrentArgument], "--config-fsm") == 0) {
				bFsmControllerFound = true;
				nCurrentArgument++;
				while (nCurrentArgument < n_argc) {
					vecConfigFsm.push_back(std::string(ppch_argv[nCurrentArgument]));
					nCurrentArgument++;
				}
				/* Do not take the FSM configuration into account in the standard command line parsing. */
				n_argc = n_argc - vecConfigFsm.size() - 1;
			}
			nCurrentArgument++;
		}

		/* Configure the command line options */
		CARGoSCommandLineArgParser cACLAP;
		cACLAP.AddFlag(
				'r',
				"readable-fsm",
				"Creates a readable version of the Finite State Machine [OPTIONAL]",
				bReadableFSM);
		cACLAP.AddFlag(
				'l',
				"history",
				"Keeps track of the states of the FSM that are exploited [OPTIONAL]",
				bHistoryFSM);
				
		// Parse command line without taking the configuration of the FSM into account
		cACLAP.Parse(n_argc, ppch_argv);
		
		CSimulator& cSimulator = CSimulator::GetInstance();

		switch(cACLAP.GetAction()) {
         case CARGoSCommandLineArgParser::ACTION_RUN_EXPERIMENT: {
				CDynamicLoading::LoadAllLibraries();
				cSimulator.SetExperimentFileName(cACLAP.GetExperimentConfigFile());
				std::cout << "*** AutoMoDe launching ***" << std::endl;
				std::cout << "   Readable format: " << bReadableFSM << std::endl;
				std::cout << "   History: " << bHistoryFSM << std::endl;
			
				// Creation of the Finite State Machine
				AutoMoDeFsmBuilder cBuilder = AutoMoDeFsmBuilder();
				AutoMoDeFiniteStateMachine* cFiniteStateMachine = cBuilder.BuildFiniteStateMachine(vecConfigFsm);
				// If the URL of the Finite State Machine is requested, display it
				if (bReadableFSM) {
					std::cout << cFiniteStateMachine->GetReadableFormat() << std::endl;
				}
				
				if (bHistoryFSM) {
					cFiniteStateMachine->MaintainHistory();
				}
				
				cSimulator.LoadExperiment();
				
				CSpace::TMapPerType cEntities = cSimulator.GetSpace().GetEntitiesByType("controller");
				for (CSpace::TMapPerType::iterator it = cEntities.begin(); it != cEntities.end(); ++it) {
					CControllableEntity* pcEntity = any_cast<CControllableEntity*>(it->second);
					AutoMoDeFiniteStateMachine* pcPersonalFsm = new AutoMoDeFiniteStateMachine(cFiniteStateMachine);
					try {
						AutoMoDeController& cController = dynamic_cast<AutoMoDeController&> (pcEntity->GetController());
						cController.SetFiniteStateMachine(pcPersonalFsm);
					} catch (std::exception& ex) {
						LOGERR << "Error while casting: " << ex.what() << std::endl;
					}
				}
				
				cSimulator.Execute();
				break;
			}
            
         case CARGoSCommandLineArgParser::ACTION_QUERY:
            CDynamicLoading::LoadAllLibraries();
            QueryPlugins(cACLAP.GetQuery());
            break;
         case CARGoSCommandLineArgParser::ACTION_SHOW_HELP:
            cACLAP.PrintUsage(LOG);
            break;
		 case CARGoSCommandLineArgParser::ACTION_SHOW_VERSION:
            cACLAP.PrintVersion();
            break;
         case CARGoSCommandLineArgParser::ACTION_UNKNOWN:
            /* Should never get here */
            break;
		}
	} 
	catch(std::exception& ex) {
      /* A fatal error occurred: dispose of data, print error and exit */
      LOGERR << ex.what() << std::endl;
#ifdef ARGOS_THREADSAFE_LOG
      LOG.Flush();
      LOGERR.Flush();
#endif
      return 1;
   }
   /* Everything's ok, exit */
   return 0;
}
