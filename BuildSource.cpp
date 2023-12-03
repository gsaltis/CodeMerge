/*****************************************************************************
 * FILE NAME    : BuildSource.cpp
 * DATE         : December 02 2023
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
#include "BuildSource.h"

/*****************************************************************************!
 * Function : BuildSource
 *****************************************************************************/
BuildSource::BuildSource
() : QWidget()
{
}

BuildSource::BuildSource
(QString InTrackName, QString InTargetName, QString InSourceName, QString InModuleName, QString InSourceType)
{
  Set(InTrackName, InTargetName, InSourceName, InModuleName, InSourceType);
}

/*****************************************************************************!
 * Function : ~BuildSource
 *****************************************************************************/
BuildSource::~BuildSource
()
{
}

/*****************************************************************************!
 * Function : Set
 *****************************************************************************/
void
BuildSource::Set
(QString InTrackName, QString InTargetName, QString InSourceName, QString InModuleName, QString InSourceType)
{
  TrackName = InTrackName;
  TargetName = InTargetName;
  SourceName = InSourceName;
  ModuleName = InModuleName;
  SourceType = InSourceType;
}
