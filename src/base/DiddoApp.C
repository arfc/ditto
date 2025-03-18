#include "DittoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DittoApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

DittoApp::DittoApp(InputParameters parameters) : MooseApp(parameters)
{
  DittoApp::registerAll(_factory, _action_factory, _syntax);
}

DittoApp::~DittoApp() {}

void
DittoApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<DittoApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"DittoApp"});
  Registry::registerActionsTo(af, {"DittoApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DittoApp::registerApps()
{
  registerApp(DittoApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DittoApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DittoApp::registerAll(f, af, s);
}
extern "C" void
DittoApp__registerApps()
{
  DittoApp::registerApps();
}
