#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <fun4all/Fun4AllServer.h>
#include <g4main/PHG4Reco.h>
#endif

// stupid macro to turn on the geant4 display
// we ask Fun4All for a pointer to PHG4Reco
// using the ApplyCommand will start up the
// G4 cmd interpreter and graphics system
// the vis.mac contains the necessary commands to
// start up the visualization, the next event will
// be displayed. Do not execute this macro
// before PHG4Reco was registered with Fun4All
PHG4Reco * DisplayOn(const char *mac = "vis.mac")
{
  char cmd[100];
  Fun4AllServer *se = Fun4AllServer::instance();
  PHG4Reco *g4 = (PHG4Reco *) se->getSubsysReco("PHG4RECO");
  g4->InitRun(se->topNode());
  sprintf(cmd, "/control/execute %s", mac);
  g4->ApplyCommand(cmd);
  return g4;
}
// print out the commands I always forget
void displaycmd()
{
  cout << "draw axis: " << endl;
  cout << " g4->ApplyCommand(\"/vis/scene/add/axes 0 0 0 50 cm\")" << endl;
  cout << "zoom" << endl;
  cout << " g4->ApplyCommand(\"/vis/viewer/zoom 1\")" << endl;
  cout << "viewpoint:" << endl;
  cout << " g4->ApplyCommand(\"/vis/viewer/set/viewpointThetaPhi 0 0\")" << endl;
  cout << "panTo:" << endl;
  cout << " g4->ApplyCommand(\"/vis/viewer/panTo 0 0 cm\")" << endl;
  cout << "print to eps:" << endl;
  cout << " g4->ApplyCommand(\"/vis/ogl/printEPS\")" << endl;
  cout << "set background color:" << endl;
  cout << " g4->ApplyCommand(\"/vis/viewer/set/background white\")" << endl;
}
