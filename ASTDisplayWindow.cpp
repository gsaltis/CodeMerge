/*****************************************************************************
 * FILE NAME    : ASTDisplayWindow.cpp
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
#include "ASTDisplayWindow.h"

/*****************************************************************************!
 * Function : ASTDisplayWindow
 *****************************************************************************/
ASTDisplayWindow::ASTDisplayWindow
() : QWidget()
{
  QPalette pal;
  level = 0;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(253, 242, 233)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ASTDisplayWindow
 *****************************************************************************/
ASTDisplayWindow::~ASTDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ASTDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ASTDisplayWindow::CreateSubWindows()
{
  elementWindow = new ASTElementWindow();
  elementWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ASTDisplayWindow::InitializeSubWindows()
{
  elementWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ASTDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   elementWindowW;
  int                                   elementWindowH;
  int                                   elementWindowY;
  int                                   elementWindowX;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  elementWindowX = 0;
  elementWindowY = 0;
  elementWindowW = width;
  elementWindowH = height;
  elementWindow->move(elementWindowX, elementWindowY);
  elementWindow->resize(elementWindowW, elementWindowH);
}

/*****************************************************************************!
 * Function : GetASTFileName
 *****************************************************************************/
QString
ASTDisplayWindow::GetASTFileName(void)
{
  return ASTFileName;  
}

/*****************************************************************************!
 * Function : SetASTFileName
 *****************************************************************************/
void
ASTDisplayWindow::SetASTFileName
(QString InASTFileName)
{
  ASTFileName = InASTFileName;
}

/*****************************************************************************!
 * Function : ASTProcess
 *****************************************************************************/
void
ASTDisplayWindow::ASTProcess
()
{
  CXCursor                              cursor;
  elementWindow->clear();
  ASTIndex = clang_createIndex(1, 1);
  TranslationUnit = clang_createTranslationUnit(ASTIndex, ASTFileName.toStdString().c_str());
  cursor = clang_getTranslationUnitCursor(TranslationUnit);
  clang_visitChildren(cursor, ASTDisplayWindow::VisitChildrenCB, this);
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
ASTDisplayWindow::SlotCompileSuccess
(QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  elementWindow->clear();
  SetFileName(InFileName);
  SetASTFileName(InASTPath);
  ASTProcess();
  (void)InErrors;
  (void)InOutput;
}

/*****************************************************************************!
 * Function : GetLevel
 *****************************************************************************/
uint32_t 
ASTDisplayWindow::GetLevel(void)
{
  return level;  
}

/*****************************************************************************!
 * Function : SetLevel
 *****************************************************************************/
void
ASTDisplayWindow::SetLevel
(uint32_t  InLevel)
{
  level = InLevel;  
}

/*****************************************************************************!
 * Function : IncreaseLevel
 *****************************************************************************/
void
ASTDisplayWindow::IncreaseLevel(void)
{
  level++;
}

/*****************************************************************************!
 * Function : DecreaseLevel
 *****************************************************************************/
void
ASTDisplayWindow::DecreaseLevel(void)
{
  if ( level > 0 ) {
    level--;
  }
}

/*****************************************************************************!
 * Function : VisitChildrenCB
 *****************************************************************************/
CXChildVisitResult
ASTDisplayWindow::VisitChildrenCB
(CXCursor InCursor, CXCursor, CXClientData InClientData)
{
  ASTDisplayWindow*                     thisPointer;

  thisPointer = (ASTDisplayWindow*)InClientData;
  thisPointer->ProcessASTCursor(InCursor);
  thisPointer->IncreaseLevel();
  clang_visitChildren(InCursor, ASTDisplayWindow::VisitChildrenCB, thisPointer);
  thisPointer->DecreaseLevel();
  return CXChildVisit_Continue;
}

/*****************************************************************************!
 * Function : ProcessASTCursor
 *****************************************************************************/
void
ASTDisplayWindow::ProcessASTCursor
(CXCursor InASTCursor)
{
  CXString                              cursorFilename;
  QString                               localFilename;
  CXSourceLocation                      loc;
  CXFile                                file;
  unsigned int                          line;
  unsigned int                          column;
  unsigned int                          offset;

  loc = clang_getCursorLocation(InASTCursor);
  clang_getSpellingLocation(loc, &file, &line, &column, &offset);
  
  cursorFilename = clang_getFileName(file);
  localFilename = QString(clang_getCString(cursorFilename));

  if ( localFilename != FileName ) {
    clang_disposeString(cursorFilename);
    return;
  }
  elementWindow->AddItem(level, InASTCursor);
  clang_disposeString(cursorFilename);
}

/*****************************************************************************!
 * Function : GetFileName
 *****************************************************************************/
QString
ASTDisplayWindow::GetFileName(void)
{
  return FileName;  
}

/*****************************************************************************!
 * Function : SetFileName
 *****************************************************************************/
void
ASTDisplayWindow::SetFileName
(QString InFileName)
{
  FileName = InFileName;  
}

/*****************************************************************************!
 * Function : SlotTreeClear
 * Purpose  : Send 'Clear Source Tree Window' message 
 *****************************************************************************/
void
ASTDisplayWindow::SlotTreeClear()
{
  emit SignalTreeClear();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ASTDisplayWindow::CreateConnections(void)
{
  connect(this,
          ASTDisplayWindow::SignalTreeClear,
          elementWindow,
          ASTElementWindow::SlotTreeClear);
}
