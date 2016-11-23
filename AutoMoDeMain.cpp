
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/entity/entity.h>
#include <argos3/core/simulator/entity/controllable_entity.h>
#include <argos3/core/utility/plugins/dynamic_loading.h>
//#include <argos3/core/simulator/query_plugins.h>
#include <argos3/core/simulator/argos_command_line_arg_parser.h>

#include "./finite_state_machine/AutoMoDeFiniteStateMachine.h"
#include "./finite_state_machine/AutoMoDeFsmBuilder.h"
#include "./AutoMoDeController.h"

using namespace argos;

/**
 * @brief
 *
 */
int main(int n_argc, char** ppch_argv) {

	bool bReadableFSM = false;
	bool bHistoryFSM = false;
	std::vector<std::string> vecConfigFsm;
	bool bFsmControllerFound = false;
	std::string strHistoryFolder = "./";

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
			} else {
				THROW_ARGOSEXCEPTION("Missing finite state machine configuration: \n\n\t --config-fsm CONF \t the finite state machine description \n");
			}
			nCurrentArgument++;
		}

		/* Configure the command line options */
		CARGoSCommandLineArgParser cACLAP;
		cACLAP.AddFlag(
				'r',
				"readable-fsm",
				"Creates an url containing a DOT representation of the finite state machine [OPTIONAL]",
				bReadableFSM);
		cACLAP.AddFlag(
				'l',
				"history",
				"Keeps track of the successive states of the finite state machine [OPTIONAL]",
				bHistoryFSM);
		cACLAP.AddArgument<std::string>(
				't',
				"history-folder",
				"The path to the folder where the history of the finite state machine will be stored [OPTIONAL]",
				strHistoryFolder);
		// Parse command line without taking the configuration of the FSM into account
		cACLAP.Parse(n_argc, ppch_argv);

		CSimulator& cSimulator = CSimulator::GetInstance();

		switch(cACLAP.GetAction()) {
    	case CARGoSCommandLineArgParser::ACTION_RUN_EXPERIMENT: {
				CDynamicLoading::LoadAllLibraries();
				cSimulator.SetExperimentFileName(cACLAP.GetExperimentConfigFile());
				std::cout << cACLAP.GetExperimentConfigFile() << std::endl;
				std::cout << "*** AutoMoDe launching ***" << std::endl;
				std::cout << "   Readable format: " << bReadableFSM << std::endl;
				std::cout << "   History: " << bHistoryFSM << std::endl;

				// Creation of the finite state machine.
				AutoMoDeFsmBuilder cBuilder = AutoMoDeFsmBuilder();
				AutoMoDeFiniteStateMachine* cFiniteStateMachine = cBuilder.BuildFiniteStateMachine(vecConfigFsm);

				// If the URL of the finite state machine is requested, display it.
				if (bReadableFSM) {
					std::cout << cFiniteStateMachine->GetReadableFormat() << std::endl;
				}

				// If an history is requested, maintain it.
				if (bHistoryFSM) {
					cFiniteStateMachine->MaintainHistory(strHistoryFolder);
				}

				cSimulator.LoadExperiment();

				// Duplicate the finite state machine and pass it to all robots.
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
        //QueryPlugins(cACLAP.GetQuery());
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
	} catch(std::exception& ex) {
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
