

# Library with test functions.
ADD_SUBDIRECTORY(src)

# Test definitions

IF (NOT Trilinos_NO_32BIT_GLOBAL_INDICES)
	ADD_SUBDIRECTORY(BlockMap)
	ADD_SUBDIRECTORY(BasicPerfTest)
	ADD_SUBDIRECTORY(Comm)
	ADD_SUBDIRECTORY(CrsGraph)
	ADD_SUBDIRECTORY(CrsMatrix)
	ADD_SUBDIRECTORY(RowMatrix)
	ADD_SUBDIRECTORY(CrsRectMatrix)
	ADD_SUBDIRECTORY(Directory)
	ADD_SUBDIRECTORY(FECrsGraph)
	ADD_SUBDIRECTORY(FECrsMatrix)
	ADD_SUBDIRECTORY(FEVbrMatrix)
	ADD_SUBDIRECTORY(FEVector)
	ADD_SUBDIRECTORY(FusedImportExport)
	ADD_SUBDIRECTORY(ImportExport)
	ADD_SUBDIRECTORY(IntMultiVector)
	ADD_SUBDIRECTORY(IntMultiVectorDistributed)
	ADD_SUBDIRECTORY(IntSerialDense)
	ADD_SUBDIRECTORY(Map)
	ADD_SUBDIRECTORY(MapColoring)
	ADD_SUBDIRECTORY(MultiVector)
	ADD_SUBDIRECTORY(Object)
	ADD_SUBDIRECTORY(RowMatrixTransposer)
	ADD_SUBDIRECTORY(SerialDense)
	ADD_SUBDIRECTORY(SerialSpdDense)
	ADD_SUBDIRECTORY(VbrMatrix)
	ADD_SUBDIRECTORY(Vector)
	ADD_SUBDIRECTORY(Bugs)
ENDIF()

IF (NOT Trilinos_NO_64BIT_GLOBAL_INDICES)
	ADD_SUBDIRECTORY(SimpleLongLongTest)
	ADD_SUBDIRECTORY(BlockMap_LL)
	ADD_SUBDIRECTORY(BasicPerfTest_LL)
	ADD_SUBDIRECTORY(CrsGraph_LL)
	ADD_SUBDIRECTORY(CrsMatrix_LL)
	ADD_SUBDIRECTORY(FusedImportExport_LL)
	ADD_SUBDIRECTORY(RowMatrix_LL)
	ADD_SUBDIRECTORY(CrsRectMatrix_LL)
	ADD_SUBDIRECTORY(Directory_LL)
	ADD_SUBDIRECTORY(FECrsGraph_LL)
	ADD_SUBDIRECTORY(FECrsMatrix_LL)
	ADD_SUBDIRECTORY(ImportExport_LL)
	ADD_SUBDIRECTORY(Map_LL)
	ADD_SUBDIRECTORY(MapColoring_LL)
	ADD_SUBDIRECTORY(SerialDense_LL)
	ADD_SUBDIRECTORY(Bugs_LL)
ENDIF()

IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/OSKI)
  ADD_SUBDIRECTORY(OSKI)
ENDIF()
