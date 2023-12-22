[Mesh]
    type=GeneratedMesh
    dim=2
    nx=20
    ny=20
[]

[Variables]
    [u]
    []
[]


[Kernels]
    [diffusion]
        type = LaplaceYoungDiffusion
        variable = u
    []
    [source]
        type = LaplaceYoungSource
        variable = u
        kappa = 0.9
    []
[]

[BCs]
  [inlet]
    type = ADNeumannBC # Simple u=value BC
    variable = u # Variable to be set
    boundary = left # Name of a sideset in the mesh
    value = 0.2
  []
  [outlet]
    type = ADNeumannBC
    variable = u
    boundary = right
    value = 0.2
  []
  
  [upprt]
    type = ADNeumannBC
    variable = u
    boundary = top
    value = 0.2
  []
  
  [lower]
    type = ADNeumannBC
    variable = u
    boundary = bottom
    value = 0.2
  []
[]

# When using PJFNK at each linear iteration we compute residual to estimate jacobian.
# When we choose Newton we calculate Jacobian up front 
# Default is PJFNK
[Executioner]
    type = Steady
    solve_type = NEWTON
[]

[Outputs]
    exodus = true
[]