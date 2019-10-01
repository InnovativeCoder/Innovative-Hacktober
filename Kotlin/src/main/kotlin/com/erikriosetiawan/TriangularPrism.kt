package com.erikriosetiawan

data class TriangularPrism(
    var pedestralArea: Double? = null,
    var height: Double? = null,
    var aroundArea: Double? = null
) {
    fun volume() = pedestralArea!! * height!!

    fun surfaceArea() = aroundArea!! * height!! + (2 * pedestralArea!!)
}