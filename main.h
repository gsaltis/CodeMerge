/*****************************************************************************
 * FILE NAME    : main.h
 * DATE         : November 29 2023
 * PROJECT      : CodeMerge
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _main_h_
#define _main_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QGuiApplication>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSettings.h"
#include "BuildModuleSet.h"
#include "CodeDatabase.h"

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/
extern
MainSettings*
MainSystemSettings;

extern
QHash<QString, BuildModuleSet*>
MainBuildModules;

extern
CodeDatabase*
MainCodeDatabase;

#endif /* _main_h_*/
