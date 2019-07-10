#include "NuFuelPApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<NuFuelPApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

NuFuelPApp::NuFuelPApp(InputParameters parameters) : MooseApp(parameters)
{
  NuFuelPApp::registerAll(_factory, _action_factory, _syntax);
}

NuFuelPApp::~NuFuelPApp() {}

void
NuFuelPApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"NuFuelPApp"});
  Registry::registerActionsTo(af, {"NuFuelPApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
NuFuelPApp::registerApps()
{
  registerApp(NuFuelPApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
NuFuelPApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  NuFuelPApp::registerAll(f, af, s);
}
extern "C" void
NuFuelPApp__registerApps()
{
  NuFuelPApp::registerApps();
}
