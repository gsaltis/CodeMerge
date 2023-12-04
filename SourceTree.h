/*****************************************************************************
 * FILE NAME    : SourceTree.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _sourcetree_h_
#define _sourcetree_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SOURCE_TREE_X                   200
#define SOURCE_TREE_Y                   200
#define SOURCE_TREE_WIDTH               200
#define SOURCE_TREE_HEIGHT              200

/*****************************************************************************!
 * Exported Class : SourceTree
 *****************************************************************************/
class SourceTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SourceTree                    ();

 //! Destructor
 public :
  ~SourceTree                   ();

 //! Public Methods
 public :
  void                          AddModuleSet            (BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateConnections       (void);
  int                           Execute                 (QString &InErrors, QString &InOutput, QString InArgs, BuildModuleSet* InModuleSet);
  void                          ExecuteSetup            (BuildModuleSet* InModuleSet);
  void                          ProcessOutput           (QString InOutput);
  void                          ProcessError            (QString InError);
  
 //! Private Data
 private :
  BuildModuleSet*               ModuleSet1;
  BuildModuleSet*               ModuleSet2;

 //! Public Slots
 public slots :
  void                          SlotItemSelected        (QTreeWidgetItem* InItem);
  void                          SlotFilesSelected       (QString InFileName1, QString InASTPath1, QString InLocalIncludeDir1,
                                                         QString InFileName2, QString InASTPath2, QString InLocalIncludeDir2);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _sourcetree_h_*/
