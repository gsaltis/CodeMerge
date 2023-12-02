/*****************************************************************************
 * FILE NAME    : ModuleWindow.cpp
 * DATE         : November 29 2023
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
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Modules", this);

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
  
  moduleTree = new ModuleTree();
  moduleTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleWindow::InitializeSubWindows()
{
  header = NULL;  
  binariesSection = NULL;
  librariesSection = NULL;
  loadableObjectsSection = NULL;
  headersSection = NULL;
  othersSection = NULL;
  moduleTree = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   moduleTreeW;
  int                                   moduleTreeH;
  int                                   moduleTreeY;
  int                                   moduleTreeX;
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
  int                                   headerW;
  int                                   headerY;
  int                                   headerX;
  int                                   headerH;
  QSize					size;  
  int					width;
  int					height;

  (void)height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = MAIN_WINDOW_HEADER_HEIGHT;

  header->move(headerX, headerY);
  header->resize(headerW, headerH);

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

  moduleTreeX = 0;
  moduleTreeY = MAIN_WINDOW_HEADER_HEIGHT;
  moduleTreeW = width;
  moduleTreeH = height - MAIN_WINDOW_HEADER_HEIGHT;
  moduleTree->move(moduleTreeX, moduleTreeY);
  moduleTree->resize(moduleTreeW, moduleTreeH);
}

/*****************************************************************************!
 * Function : PostWindowCreateProcess
 *****************************************************************************/
void
ModuleWindow::PostWindowCreateProcess(void)
{
  QList<QString>                        keys;
  keys = MainBuildModules.keys();
  moduleTree->AddModuleSet(MainBuildModules[keys[0]], MainBuildModules[keys[1]]);
}
