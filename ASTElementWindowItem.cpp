/*****************************************************************************
 * FILE NAME    : ASTElementWindowItem.cpp
 * DATE         : December 05 2023
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
#include "ASTElementWindowItem.h"

/*****************************************************************************!
 * Function : ASTElementWindowItem
 *****************************************************************************/
ASTElementWindowItem::ASTElementWindowItem
() : QWidget(), QTreeWidgetItem()
{
  initialize();
}

/*****************************************************************************!
 * Function : SetCursor
 *****************************************************************************/
void
ASTElementWindowItem::SetCursor
(CXCursor InASTCursor)
{
  CXCursorKind                          kind;
  CXString                              cursorkindName;
  QString                               kindName;
  
  CXString                              cursorText;
  QString                               elementName;
  
  kind = clang_getCursorKind(InASTCursor);
  cursorkindName = clang_getCursorKindSpelling(kind);
  kindName = QString(clang_getCString(cursorkindName));
                     
  cursorText = clang_getCursorSpelling(InASTCursor);
  elementName = QString(clang_getCString(cursorText));

  setText(0, kindName);
  setText(1, elementName);
}

/*****************************************************************************!
 * Function : ~ASTElementWindowItem
 *****************************************************************************/
ASTElementWindowItem::~ASTElementWindowItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ASTElementWindowItem::initialize()
{
}

