#include "LaplaceYoungDiffusion.h"

registerMooseObject("creatorApp", LaplaceYoungDiffusion);


InputParameters
LaplaceYoungDiffusion::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for laplace equation");
  return params;
}

// Why do we mention the inheritence here but not at the DarcyPressure? 
LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters) : ADKernelGrad(parameters)
{
}

ADRealVectorValue
LaplaceYoungDiffusion::precomputeQpResidual()
{   
    // Using ADKernelGrad automatically handles the gradient of test function
    // Why do we need the dot in ./?
    ADReal k = 1./std::sqrt(1.0+_grad_u[_qp]*_grad_u[_qp]); // Type ADReal is important for this coefficient
    return k * _grad_u[_qp];
}


// For a practice don't use AD and compute jacobian yourself, see how it is 