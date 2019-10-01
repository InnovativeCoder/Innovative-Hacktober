package com.erikriosetiawan

data class Cylinder(var pedestralArea: Double? = null, var height: Double? = null, var aroundArea: Double? = null) {

    fun volume() = pedestralArea!! * height!!

    fun surfaceArea() = (2 * pedestralArea!!) + (aroundArea!! * height!!)
}