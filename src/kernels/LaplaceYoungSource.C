#include "LaplaceYoungSource.h"

registerMooseObject("creatorApp", LaplaceYoungSource);


InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addParam<Real>("kappa",1,"Coefficient to the laplace source term");
  params.addClassDescription("Compute the source term for laplace equation");
  return params;
}

// Why do we mention the inheritence here but not at the DarcyPressure? 
LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters) : 
ADKernelValue(parameters),
_kappa(getParam<Real>("kappa")) // Initializing _kappa (initialized in .h) to be "kappa" (user input)
{
}

// This type also has to be changed to ADReal 
ADReal
LaplaceYoungSource::precomputeQpResidual()
{   
   return _kappa * _u[_qp];
}


// For a practice don't use AD and compute jacobian yourself, see how it is 