package com.erikriosetiawan

data class Cuboids(var length: Double? = null, var width: Double? = null, var height: Double? = null) {

    fun volume() = (length!! * width!! * height!!)

    fun surfaceArea() = (2 * length!! * width!!) + (2 * length!! * height!!) + (2 * width!! * height!!)
}