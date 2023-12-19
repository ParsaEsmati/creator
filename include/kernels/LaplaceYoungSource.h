#pragma once 

// We change ADKernelGrad to ADKernelValue because wewant to multiply by the test function
// only and not the grad of test function 
#include "ADKernelValue.h"

class LaplaceYoungSource : public ADKernelValue
{
public:
  static InputParameters validParams();

  LaplaceYoungSource(const InputParameters & parameters);

protected:
  /// ADKernel objects must override precomputeQpResidual
  // We also change ADRealVector to ADReal cause that's what we return
  virtual ADReal precomputeQpResidual() override;

  // If not derivative info coming we use Real and not ADReal
  const Real & _kappa;
};

