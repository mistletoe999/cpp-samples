#include "Array.hpp"
#include "Point.hpp"

namespace KAPIL
{
	namespace Containers
	{
		// Default Constructor
		Array::Array()
		{
			m_size = 10;
			m_data = new CAD::Point[m_size];
		}

		// Constrcutor with size parameter
		Array::Array(unsigned int size)
		{
			m_size = size;
			m_data = new CAD::Point[m_size];
		}

		// Copy Constructor
		Array::Array(const Array& arr)
		{
			m_size = arr.m_size;
			m_data = new CAD::Point[m_size];

			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = arr.m_data[i];
			}
		}

		// Destructor
		Array::~Array()
		{
			delete[] m_data;		// Delete the dynamically allocated memory
			m_data = 0;				// Assign pointer to NULL
		}

		// Member Functions
		unsigned int Array::Size() const
		{
			return m_size;
		}

		// Setter Function
		void Array::SetElement(unsigned int index, const CAD::Point& p)
		{
			if (index >= 0 && index < m_size) {
				m_data[index] = p;
			}
			else {
				throw -1;
			}
		}

		// Getter Function 
		CAD::Point& Array::GetElement(unsigned int index) const
		{
			if (index >= 0 && index < m_size) {
				return m_data[index];
			}
			else {
				throw -1;
			}
		}


		// Operators
		Array& Array::operator=(const Array& source)
		{
			// Self Assignment Check
			if (this == &source)
			{
				return *this;
			}

			// First we need to deallocate the value m_data is currently holding
			delete[] m_data;

			// Get the size of the source array
			m_size = source.m_size;


			if (source.m_data) // Check whether source m_data is pointing to null 
			{
				// Initialize m_data again on the heap
				m_data = new CAD::Point[m_size];
				// Copy elements
				for (int i = 0; i < m_size; i++)
				{
					// Copy individual elements
					m_data[i] = source.m_data[i];
				}
			}
			else {
				m_data = 0;
			}

			return *this;
		}


		// [] operator
		CAD::Point& Array::operator [] (int index)
		{
			if (index >= 0 && index < m_size)
			{
				return m_data[index];
			}
			else
			{
				throw -1;
			}
		}

		// [] operator
		const CAD::Point& Array::operator [] (int index) const
		{
			if (index >= 0 && index < m_size)
			{
				return m_data[index];
			}
			else
			{
				throw -1;
			}
		}
	}
}

