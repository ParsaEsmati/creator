#pragma once 

#include "Material.h"

#include "LinearInterpolation.h"

// Creating a material class that inherits from MOOSE Material
class PackedColumn : public Material
{
    public: 

        // What's this?
        static InputParameters validParams();

        // Declaration of constructor with one input "parameters" and 
        //the "InputParameters" data type, which is constant.
        PackedColumn(const InputParameters & parameters);
    protected:

        // This is a virtual function, likely overriding a base class method. 
        //It's used to compute properties at a quadrature point (Qp). 
        //The override keyword ensures that this function is indeed overriding a method from the base class.
        virtual void computeQpProperties() override;

        // Declaration of _radius which has a type Function
        const Function & _radius;

        // Declaration of _input_viscoisity which has a type Real
        const Real & _input_viscosity;

        // Declaration of _permeability_interpolation which has a type LinearInterpolation
        LinearInterpolation _permeability_interpolation;

        ADMaterialProperty<Real> & _permeability;

        ADMaterialProperty<Real> & _viscosity; 
}