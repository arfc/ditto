//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DiddoTestApp.h"
#include "DiddoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
DiddoTestApp::validParams()
{
  InputParameters params = DiddoApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

DiddoTestApp::DiddoTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DiddoTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DiddoTestApp::~DiddoTestApp() {}

void
DiddoTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DiddoApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DiddoTestApp"});
    Registry::registerActionsTo(af, {"DiddoTestApp"});
  }
}

void
DiddoTestApp::registerApps()
{
  registerApp(DiddoApp);
  registerApp(DiddoTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DiddoTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DiddoTestApp::registerAll(f, af, s);
}
extern "C" void
DiddoTestApp__registerApps()
{
  DiddoTestApp::registerApps();
}
