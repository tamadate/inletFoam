#include <fvCFD.H>
#include <OFstream.H>  // Include this to write to a file

int main(int argc, char* argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"

    const volVectorField& C = mesh.C();
    const label patchID = mesh.boundaryMesh().findPatchID("inlet");

    const polyPatch& inletPatch = mesh.boundaryMesh()[patchID];
    const labelList& faceCells = inletPatch.faceCells();

    // Create an output file
    OFstream outFile("faceCenters.txt");
	outFile << "faceID\tx\ty\tz" << endl;

    forAll(faceCells, i)
    {
        label cellID = faceCells[i];
        const point& faceCenter = C[cellID];
        outFile << i << "\t" << faceCenter.x() << "\t" << faceCenter.y() << "\t" << faceCenter.z() << endl;
    }

    return 0;
}

