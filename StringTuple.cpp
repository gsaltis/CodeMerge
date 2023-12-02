/*****************************************************************************
 * FILE NAME    : StringTuple.cpp
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
#include "StringTuple.h"

/*****************************************************************************!
 * Function : StringTuple
 *****************************************************************************/
StringTuple::StringTuple
(QString InString1, QString InString2) : QWidget()
{
  string1 = InString1;
  string2 = InString2;
}

/*****************************************************************************!
 * Function : StringTuple
 *****************************************************************************/
StringTuple::StringTuple
() : QWidget()
{
  string1 = QString();
  string2 = QString();
}

/*****************************************************************************!
 * Function : ~StringTuple
 *****************************************************************************/
StringTuple::~StringTuple
()
{
}

/*****************************************************************************!
 * Function : GetString1
 *****************************************************************************/
QString
StringTuple::GetString1(void)
{
  return string1;  
}

/*****************************************************************************!
 * Function : SetString1
 *****************************************************************************/
void
StringTuple::SetString1
(QString InString1)
{
  string1 = InString1;  
}

/*****************************************************************************!
 * Function : GetString2
 *****************************************************************************/
QString
StringTuple::GetString2(void)
{
  
  return string2;
}

/*****************************************************************************!
 * Function : SetString2
 *****************************************************************************/
void
StringTuple::SetString2
(QString InString2)
{
  
  string2 = InString2;
}

/*****************************************************************************!
 * Function : Compare
 *****************************************************************************/
int
StringTuple::Compare
(StringTuple InTuple)
{
  QString                       s1;
  QString                       s2;
  

  s1 = string1.isEmpty() ? string1 : string2;
  s2 = InTuple.GetString1().isEmpty() ? InTuple.GetString2() : InTuple.GetString1();

  if ( s1.isEmpty() && s2.isEmpty() ) {
    return 0;
  }

  if ( s1.isEmpty() ) {
    return 1;
  }

  if ( s2.isEmpty() ) {
    return -1;
  }

  if ( s1 < s2 ) {
    return 1;
  }

  if ( s2 < s1 ) {
    return -1;
  }

  return 0;
}
