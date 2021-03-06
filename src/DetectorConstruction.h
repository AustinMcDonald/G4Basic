// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.h
//
//  Class for the definition of the detector geometry and materials.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H

#include <G4VUserDetectorConstruction.hh>

class G4Material;
class G4GenericMessenger;

class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  virtual ~DetectorConstruction();
  virtual G4VPhysicalVolume* Construct();
private:
  G4Material* DefineNeon() const;
  G4GenericMessenger* msg_; // Messenger for configuration parameters
  double density_;
  double pressure_;
  double temperature_;

};

#endif
