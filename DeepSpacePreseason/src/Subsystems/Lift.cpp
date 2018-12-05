// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"


#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/ControlLift.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Lift::Lift() : frc::Subsystem("Lift") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    talonLift = RobotMap::liftTalonLift;
    encoder = RobotMap::liftEncoder;
    liftController = RobotMap::liftLiftController;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Lift::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Lift::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lift::controlLift(std::shared_ptr<Joystick>mainController)
{
	double left_trigger = mainController->GetRawAxis(2);
	double right_trigger = mainController->GetRawAxis(3);
	int left_bumper = mainController->GetRawButton(5);
	int right_bumper = mainController->GetRawButton(6);

	if(left_trigger > 0.1 && right_trigger > 0.1) {
		talonLift->Set(0.0);
	}
	else if ((left_bumper == 1 || right_bumper == 1) && right_trigger == 0 && left_trigger  > 0) {
		talonLift->Set(-0.6*left_trigger);
	}
	else if ((left_bumper == 1 || right_bumper == 1) && right_trigger  > 0 && left_trigger == 0){
		talonLift->Set(0.6*right_trigger);
	}
	else if (left_bumper == 0 && right_bumper == 0 && right_trigger == 0 && left_trigger  > 0) {
		talonLift->Set(-1*left_trigger);
	}
	else if (left_bumper == 0 && right_bumper == 0 && right_trigger  > 0 && left_trigger == 0){
		talonLift->Set(right_trigger);
	}
	else {
		talonLift->Set (0);
	}

}
