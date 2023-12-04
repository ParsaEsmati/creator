#include "DarcyPressure.h"

registerMooseObject("creatorApp", DarcyPressure);


InputParameters
DarcyPressure::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");

  params.addRequiredParam<Real>("permeability", "The isotropic permeability");
  params.addParam<Real>("viscosity", 7.98e-04,"The viscosity of the medium");
  return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
  : ADKernelGrad(parameters),

    // Set the coefficients for the pressure kernel
//    _permeability(0.8451e-09),
//    _viscosity(7.98e-04)
    _permeability(getParam<Real>("permeability")),
    _viscosity(getParam<Real>("viscosity"))
{
}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
  return (_permeability / _viscosity) * _grad_u[_qp];
}