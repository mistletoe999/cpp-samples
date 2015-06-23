#include <iostream>
#include <string>

#ifndef H5_NO_NAMESPACE
#ifndef H5_NO_STD
    using std::cout;
    using std::endl;
#endif  // H5_NO_STD
#endif

#include <H5Cpp.h>

#ifndef H5_NO_NAMESPACE
using namespace H5;
#endif

const std::string FILE_NAME( "../Sample.h5" );

using namespace std;

int main() {
    H5File file(FILE_NAME, H5F_ACC_RDONLY );

    double data_out[1000][2];

    try {
        Group gp = file.openGroup("EDH6").openGroup("20150619").openGroup("quotes");
        std::cout << gp.getLocId() << std::endl;
        DataSet ds = gp.openDataSet("block0_values");
        std::cout << ds.getTypeClass() << std::endl;
        DataSpace dataspace = ds.getSpace();
        int rank = dataspace.getSimpleExtentNdims();
        hsize_t dims_out[2];
        int ndims = dataspace.getSimpleExtentDims( dims_out, NULL);
        cout << "rank " << rank << ", dimensions " <<
                (unsigned long)(dims_out[0]) << " x " <<
                (unsigned long)(dims_out[1]) << endl;

        hsize_t dimsm[2];
        dimsm[0] = 1000;
        dimsm[1] = 2;

        DataSpace memspace( 2, dimsm );

        ds.read( data_out, PredType::NATIVE_DOUBLE, memspace, dataspace );

        for (int j = 0; j < 1000; j++)
        {
            for (int i = 0; i < 2; i++)
                cout << data_out[j][i] << " ";
            cout << endl;
        }

        DataSet column_names = gp.openDataSet("block0_items");
        DataSpace col_name_ds = column_names.getSpace();
        rank = col_name_ds.getSimpleExtentNdims();
        hsize_t col_names[2];
        ndims = col_name_ds.getSimpleExtentDims( col_names, NULL);
        cout << "rank " << rank << ", dimensions " <<
        (unsigned long)(col_names[0]) << " x " <<
        (unsigned long)(col_names[1]) << endl;

        char cols[100][100];
        dimsm[0] = 2;
        dimsm[1] = 0;

        DataSpace col_space(2, dimsm);

        StrType strtype(0, H5T_VARIABLE);

        column_names.read(cols, strtype, col_name_ds);

//
//        for (int i = 0; i < 2; ++i)
//        {
//            cout << cols[i] << std::endl;
//        }

    }
    catch( FileIException error )
    {
        error.printError();
        return -1;
    }
    // catch failure caused by the DataSet operations
    catch( DataSetIException error )
    {
        error.printError();
        return -1;
    }
    // catch failure caused by the DataSpace operations
    catch( DataSpaceIException error )
    {
        error.printError();
        return -1;
    }
    // catch failure caused by the DataSpace operations
    catch( DataTypeIException error )
    {
        error.printError();
        return -1;
    }


    return 0;
}