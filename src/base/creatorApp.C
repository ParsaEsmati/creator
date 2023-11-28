#include "creatorApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
creatorApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

creatorApp::creatorApp(InputParameters parameters) : MooseApp(parameters)
{
  creatorApp::registerAll(_factory, _action_factory, _syntax);
}

creatorApp::~creatorApp() {}

void 
creatorApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<creatorApp>(f, af, s);
  Registry::registerObjectsTo(f, {"creatorApp"});
  Registry::registerActionsTo(af, {"creatorApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
creatorApp::registerApps()
{
  registerApp(creatorApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
creatorApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  creatorApp::registerAll(f, af, s);
}
extern "C" void
creatorApp__registerApps()
{
  creatorApp::registerApps();
}
