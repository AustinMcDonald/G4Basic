// -----------------------------------------------------------------------------
//  G4Basic | SteppingAction.cpp
//
//  Definition of detector geometry and materials.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#include "SteppingAction.h"

//#include <G4Step.hh>
//#include <G4Event.hh>
//#include <G4RunManager.hh>
//#include <G4GenericMessenger.hh>


SteppingAction::SteppingAction(): G4UserSteppingAction()
{
    msg_ = new G4GenericMessenger(this, "/Inputs/");
    msg_->DeclareMethod("output_file", &SteppingAction::OpenFile, "");
}


SteppingAction::~SteppingAction()
{
    delete msg_;
    Data_File.close();

}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
    double xpos, ypos, zpos;
    double stepL, hitE;
    int eID = 0;
    const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
    if(evt) eID = evt->GetEventID();
    
    hitE  = step->GetTotalEnergyDeposit();
    stepL = step->GetStepLength();
    xpos  = step->GetPostStepPoint()->GetPosition().x();
    ypos  = step->GetPostStepPoint()->GetPosition().y();
    zpos  = step->GetPostStepPoint()->GetPosition().z();
    
    Data_File <<  eID  <<"\t"<< xpos <<"\t"<< ypos <<"\t"<< zpos <<"\t"<< hitE <<"\t"<< stepL << std::endl;
    //Data_File <<  1  << "\t" << 2 << "\t" << 3<< "\t" << 4<<"\t"<< eID << std::endl;
}

void SteppingAction::OpenFile(G4String filename)
{
    Data_File.open(filename);
    Data_File << "EventID" <<"\t"<< "xpos" <<"\t"<< "ypos" <<"\t"<< "zpos" <<"\t"<< "hitE" <<"\t"<< "stepL" << std::endl;
}
