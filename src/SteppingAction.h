// -----------------------------------------------------------------------------
//  G4Basic | SteppingAction.H
//
//  Definition of detector geometry and materials.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#ifndef STEPPING_ACTION_H
#define STEPPING_ACTION_H

#include <G4UserSteppingAction.hh>

#include <fstream>
#include <G4Step.hh>
#include <G4Event.hh>
#include <G4RunManager.hh>
#include <G4GenericMessenger.hh>


class G4GenericMessenger;
class SteppingAction: public G4UserSteppingAction
{
  public:
    SteppingAction();
    virtual ~SteppingAction();
    virtual void UserSteppingAction(const G4Step*);
    void OpenFile(G4String);

private:
    G4GenericMessenger* msg_;
    G4String file_out_;
    std::ofstream Data_File;
};

#endif
