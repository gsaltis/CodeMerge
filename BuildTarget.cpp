/*****************************************************************************
 * FILE NAME    : BuildTarget.cpp
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildTarget.h"

/*****************************************************************************!
 * Function : BuildTarget
 *****************************************************************************/
BuildTarget::BuildTarget
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~BuildTarget
 *****************************************************************************/
BuildTarget::~BuildTarget
()
{
}

/*****************************************************************************!
 * Function : Set
 *****************************************************************************/
void
BuildTarget::Set
(QString InTrackName, QString InType, QString InName, QString InPath)
{
  TrackName     = InTrackName;
  Type          = InType;
  Name          = InName;
  Path          = InPath;
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
QString
BuildTarget::GetType(void)
{
  return Type;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
BuildTarget::GetName(void)
{
  return Name;
}