/*****************************************************************************
 * FILE NAME    : ModuleWindow.cpp
 * DATE         : November 29 2023
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
#include "ModuleWindow.h"
#include "main.h"

/*****************************************************************************!
 * Function : ModuleWindow
 *****************************************************************************/
ModuleWindow::ModuleWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleWindow
 *****************************************************************************/
ModuleWindow::~ModuleWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  PostWindowCreateProcess();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleWindow::CreateSubWindows()
{
  binariesSection = new ModuleSectionWindow("Binaries");
  binariesSection->setParent(this);
  
  librariesSection = new ModuleSectionWindow("Libraries");
  librariesSection->setParent(this);
  
  loadableObjectsSection = new ModuleSectionWindow("Loadable Objects");
  loadableObjectsSection->setParent(this);

  headersSection = new ModuleSectionWindow("Headers");
  headersSection->setParent(this);

  othersSection = new ModuleSectionWindow("Others");
  othersSection->setParent(this);

  binariesSection->hide();
  librariesSection->hide();
  loadableObjectsSection->hide();
  headersSection->hide();
  othersSection->hide();
  
  moduleWindow = new ModuleContainerWindow();
  moduleWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleWindow::InitializeSubWindows()
{
  binariesSection = NULL;
  librariesSection = NULL;
  loadableObjectsSection = NULL;
  headersSection = NULL;
  othersSection = NULL;
  moduleWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   moduleWindowW;
  int                                   moduleWindowH;
  int                                   moduleWindowY;
  int                                   moduleWindowX;
  int                                   othersSectionW;
  int                                   othersSectionH;
  int                                   othersSectionY;
  int                                   othersSectionX;
  int                                   headersSectionW;
  int                                   headersSectionH;
  int                                   headersSectionY;
  int                                   headersSectionX;
  int                                   loadableObjectsSectionW;
  int                                   loadableObjectsSectionH;
  int                                   loadableObjectsSectionY;
  int                                   loadableObjectsSectionX;
  int                                   librariesSectionW;
  int                                   librariesSectionH;
  int                                   librariesSectionY;
  int                                   librariesSectionX;
  int                                   binariesSectionW;
  int                                   binariesSectionH;
  int                                   binariesSectionY;
  int                                   binariesSectionX;
  QSize					size;  
  int					width;
  int					height;

  (void)height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  binariesSectionX = 0;
  binariesSectionY = MAIN_WINDOW_HEADER_HEIGHT + 10;
  binariesSectionW = width;
  binariesSectionH = 100;
  binariesSection->move(binariesSectionX, binariesSectionY);
  binariesSection->resize(binariesSectionW, binariesSectionH);

  librariesSectionX = 0;
  librariesSectionY = MAIN_WINDOW_HEADER_HEIGHT + 120;
  librariesSectionW = width;
  librariesSectionH = 100;
  librariesSection->move(librariesSectionX, librariesSectionY);
  librariesSection->resize(librariesSectionW, librariesSectionH);

  loadableObjectsSectionX = 0;
  loadableObjectsSectionY = MAIN_WINDOW_HEADER_HEIGHT + 230;
  loadableObjectsSectionW = width;
  loadableObjectsSectionH = 100;
  loadableObjectsSection->move(loadableObjectsSectionX, loadableObjectsSectionY);
  loadableObjectsSection->resize(loadableObjectsSectionW, loadableObjectsSectionH);

  headersSectionX = 0;
  headersSectionY = MAIN_WINDOW_HEADER_HEIGHT + 340;
  headersSectionW = width;
  headersSectionH = 100;
  headersSection->move(headersSectionX, headersSectionY);
  headersSection->resize(headersSectionW, headersSectionH);

  othersSectionX = 0;
  othersSectionY = MAIN_WINDOW_HEADER_HEIGHT + 430;
  othersSectionW = width;
  othersSectionH = 100;
  othersSection->move(othersSectionX, othersSectionY);
  othersSection->resize(othersSectionW, othersSectionH);

  moduleWindowX = 0;
  moduleWindowY = 0;
  moduleWindowW = width;
  moduleWindowH = height;
  moduleWindow->move(moduleWindowX, moduleWindowY);
  moduleWindow->resize(moduleWindowW, moduleWindowH);
}

/*****************************************************************************!
 * Function : PostWindowCreateProcess
 *****************************************************************************/
void
ModuleWindow::PostWindowCreateProcess(void)
{
  QList<QString>                        keys;
  keys = MainBuildModules.keys();
  std::sort(keys.begin(), keys.end());
  moduleWindow->AddModuleSet(MainBuildModules[keys[0]], MainBuildModules[keys[1]]);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ModuleWindow::CreateConnections(void)
{
  connect(moduleWindow,
          ModuleContainerWindow::SignalErrorMessage,
          this,
          ModuleWindow::SlotErrorMessage);
  connect(moduleWindow,
          ModuleContainerWindow::SignalErrorClear,
          this,
          ModuleWindow::SlotErrorClear);
  connect(moduleWindow,
          ModuleContainerWindow::SignalCompileSuccess,
          this,
          ModuleWindow::SlotCompileSuccess);
}

/*****************************************************************************!
 * Function : SlotErrorMessage
 *****************************************************************************/
void
ModuleWindow::SlotErrorMessage
(QString InErrorMessage)
{
  emit SignalErrorMessage(InErrorMessage);
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
ModuleWindow::SlotCompileSuccess
(QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  emit SignalCompileSuccess(InTrackName, InASTPath, InFileName, InErrors, InOutput);  
}

/*****************************************************************************!
 * Function : SlotErrorClear
 * Purpose  : Send 'Clear Error Display Window' message 
 *****************************************************************************/
void
ModuleWindow::SlotErrorClear()
{
  emit SignalErrorClear();
}
