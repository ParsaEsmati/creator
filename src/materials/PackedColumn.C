#include "PackedColumn.h"
#include "Function.h"

registerMooseObject("CreatorApp", PackedColumn);

InputParameters 
PackedColumn::validParams()
{

    InputParameters params = Material::validParams();


    params.addParam<FunctionName>("radius","1.0","Radius of steel spheres in mm");

    params.addParam<Real>("viscosity",7.98e-4,"Viscosity of the fluid")

    return params;

}

PackedColumn::PackedColumn(const InputParameters & parameters) 
    : Material(parameters),
    _radius(getFunction("radius")),
    _input_viscosity(getParam<Real>("viscosity")),

    _permeability(declareADProperty<Real>("permeability")),
    _viscosity(declareADProperty<Real>("viscosity"))

{

    std::vector<Real> sphere_sizes = {1,3};
    std::vector<Real> permeability = {0.8451e-9,8.968e-9};

    _permeability_interpolation.setData(sphere_sizes, permeability);

}

void PackedColumn::computeQpProperties()
{
    Real value = _radius.value(_t, _q_point[_qp]);
    mooseAssert(value>=1 && value<=3, "The radius range must be between 1 and 3, but value:"<<value<<"provided.");

    _viscosity[_qp] = _input_viscosity;
    _permeability[_qp] = _permeability_interpolation.sample(value);

}