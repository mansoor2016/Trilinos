// @HEADER
// ************************************************************************
//
//           Galeri: Finite Element and Matrix Generation Package
//                 Copyright (2006) ETHZ/Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions about Galeri? Contact Marzio Sala (marzio.sala _AT_ gmail.com)
//
// ************************************************************************
// @HEADER

#include "Galeri_Maps.h"
#include "Galeri_CrsMatrices.h"
#include "Galeri_Utils.h"
#ifdef HAVE_MPI
#include "Epetra_MpiComm.h"
#include "mpi.h"
#else
#include "Epetra_SerialComm.h"
#endif
#include "Epetra_Map.h"
#include "Epetra_CrsMatrix.h"
#include "Teuchos_ParameterList.hpp"

using namespace Galeri;

// =========== //
// main driver //
// =========== //

int main(int argc, char* argv[])
{
#ifdef HAVE_MPI
  MPI_Init(&argc, &argv);
  Epetra_MpiComm Comm(MPI_COMM_WORLD);
#else
  Epetra_SerialComm Comm;
#endif

  // pointer to the map to be created
  Epetra_Map*            Map;
  // pointer to the matrix to be created
  Epetra_CrsMatrix*      Matrix;
  // container for parameters
  Teuchos::ParameterList GaleriList;
  // here we specify the global dimension of the problem
  int nx = 5 * Comm.NumProc();
  int ny = 5 * Comm.NumProc();
  GaleriList.set("nx", nx);
  GaleriList.set("ny", ny);

  try
  {
    // Creates a simple linear map; for more details on the map creation
    // refer to the documentation
#ifndef GALERI_TEST_USE_LONGLONG_GO
    Map = CreateMap("Cartesian2D", Comm, GaleriList);
#else
    Map = CreateMap64("Cartesian2D", Comm, GaleriList);
#endif

    // Creates a diagonal matrix with 1's on the diagonal
    Matrix   = CreateCrsMatrix("Biharmonic2D", Map, GaleriList);

    // print out the matrix
    //cout << *Matrix;

    int GID = -1; // set GID to the global node to use to compute
                  // the stencil, or put -1 to automatically select it.
    PrintStencil2D(Matrix, nx, ny, GID);

    // To created objects must be free'd using delete
    delete Map;
    delete Matrix;
  }
  catch (Exception& rhs)
  {
    if (Comm.MyPID() == 0)
    {
      cerr << "Caught exception: ";
      rhs.Print();
    }
  }

#ifdef HAVE_MPI
  MPI_Finalize();
#endif

  return(EXIT_SUCCESS);
}
