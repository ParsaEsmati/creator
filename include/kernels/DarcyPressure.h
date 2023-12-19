// Following or pragma once 
#ifndef DARCYPRESSURE_H
#define DARCYPRESSURE_H

// We are going to inherit from ADKernelGrad (optimized Kernels)
// https://mooseframework.inl.gov/source/kernels/ADKernelGrad.html
#include "ADKernelGrad.h"

/**
 * Computes the residual contribution: K / mu * grad_test * grad_u.
 */
class DarcyPressure : public ADKernelGrad
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  /// ADKernel objects must override precomputeQpResidual
  virtual ADRealVectorValue precomputeQpResidual() override;

  /// The variables which hold the value for K and mu
  
  const Real & _permeability;
  const Real & _viscosity;
};

#endif