//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DittoTestApp.h"
#include "DittoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
DittoTestApp::validParams()
{
  InputParameters params = DittoApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

DittoTestApp::DittoTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DittoTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DittoTestApp::~DittoTestApp() {}

void
DittoTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DittoApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DittoTestApp"});
    Registry::registerActionsTo(af, {"DittoTestApp"});
  }
}

void
DittoTestApp::registerApps()
{
  registerApp(DittoApp);
  registerApp(DittoTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DittoTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DittoTestApp::registerAll(f, af, s);
}
extern "C" void
DittoTestApp__registerApps()
{
  DittoTestApp::registerApps();
}
