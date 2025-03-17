#include "DiddoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DiddoApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

DiddoApp::DiddoApp(InputParameters parameters) : MooseApp(parameters)
{
  DiddoApp::registerAll(_factory, _action_factory, _syntax);
}

DiddoApp::~DiddoApp() {}

void
DiddoApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<DiddoApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"DiddoApp"});
  Registry::registerActionsTo(af, {"DiddoApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DiddoApp::registerApps()
{
  registerApp(DiddoApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DiddoApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DiddoApp::registerAll(f, af, s);
}
extern "C" void
DiddoApp__registerApps()
{
  DiddoApp::registerApps();
}
