/*****************************************************************************
 * FILE NAME    : ASTElementWindow.cpp
 * DATE         : December 04 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ASTElementWindow.h"

/*****************************************************************************!
 * Function : ASTElementWindow
 *****************************************************************************/
ASTElementWindow::ASTElementWindow
() : QTreeWidget()
{
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ASTElementWindow
 *****************************************************************************/
ASTElementWindow::~ASTElementWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ASTElementWindow::initialize()
{
  itemsCount = 0;
  setColumnCount(2);
}

/*****************************************************************************!
 * Function : AddItem
 *****************************************************************************/
void
ASTElementWindow::AddItem
(int InLevel, CXCursor InASTCursor)
{
  QString                               elementName;
  QString                               outputString;
  CXSourceLocation                      loc;
  CXCursorKind                          kind;
  CXString                              kindName;
  CXFile                                file;
  unsigned int                          line;
  unsigned int                          column;
  unsigned int                          offset;
  CXString                              cursorText;
  CXType                                type;
  CXString                              cursorTypeName;
  QString                               typeName;
  ASTElementWindowItem*                 treeItem;
  
  loc = clang_getCursorLocation(InASTCursor);
  clang_getSpellingLocation(loc, &file, &line, &column, &offset);

  kind = clang_getCursorKind(InASTCursor);
  kindName = clang_getCursorKindSpelling(kind);

  type = clang_getCursorType(InASTCursor);
  cursorTypeName = clang_getTypeSpelling(type);
  typeName = QString(clang_getCString(cursorTypeName));
  
  cursorText = clang_getCursorSpelling(InASTCursor);
  elementName = QString(clang_getCString(cursorText));
  outputString = QString("%1 : %2 %3 : %4 : %5 %6").
    arg(InLevel).
    arg(line).
    arg(column).
    arg(clang_getCString(kindName)).
    arg(elementName).
    arg(typeName);

  treeItem = new ASTElementWindowItem();
  treeItem->SetCursor(InASTCursor);
  if ( InLevel == 0 ) {
    addTopLevelItem(treeItem);
  } else {
    items[InLevel-1]->addChild(treeItem);
  }
  items[InLevel] = treeItem;
  
  clang_disposeString(kindName);
  clang_disposeString(cursorText);
  clang_disposeString(cursorTypeName);
}

/*****************************************************************************!
 * Function : SlotTreeClear
 *****************************************************************************/
void
ASTElementWindow::SlotTreeClear(void)
{
  clear();
}
