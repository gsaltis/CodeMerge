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

/*****************************************************************************!
 * Function : BuildSource
 *****************************************************************************/
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

/*****************************************************************************!
 * Function : GetSourceName
 *****************************************************************************/
QString
BuildSource::GetSourceName(void)
{
  return SourceName;
}

/*****************************************************************************!
 * Function : GetModuleName
 *****************************************************************************/
QString
BuildSource::GetModuleName(void)
{
  return ModuleName;
}

/*****************************************************************************!
 * Function : NormalizeFilename
 *****************************************************************************/
QString
BuildSource::NormalizeFilename
(QString InName, QString InModuleName, QString InSourcePath)
{
  QStringList                           stl;
  QString                               st;
  int                                   n;
  int                                   i;
  int                                   j;
  QString                               st2;
  QString                               name;
  
  n = InSourcePath.length();
  name = InName;
  if ( name.left(n) == InSourcePath ) {
    name = name.sliced(n);
    while (name[0] == '/' ) {
      name = name.sliced(1);
    }
    return name;
  }
  if ( name[0] == '/' ) {
    name = name.sliced(1);
    return name;
  }
  st = InModuleName + QString("/") + name;
  stl = st.split("/");

  st2 = QString();
  n = stl.size();

  for ( i = 0 ; i < n ; i++ ) {
    j = i + 1;
    if ( j < n ) {
      if ( stl[j] == ".." ) {
        i = j;
        continue;
      }
    }
    if ( !st2.isEmpty() ) {
      st2 += "/";
    }
    st2 += stl[i];
  }         
  return st2;
}


