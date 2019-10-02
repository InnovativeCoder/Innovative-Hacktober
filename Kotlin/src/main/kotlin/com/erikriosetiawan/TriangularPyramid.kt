package com.erikriosetiawan

data class TriangularPyramid(
    var pedestralArea: Double? = null,
    var height: Double? = null,
    var coveringArea: Double? = null
) {

    fun volume() = 1.0 / 3.0 * pedestralArea!! * height!!

    fun surfaceArea() = pedestralArea!! + coveringArea!!
}
