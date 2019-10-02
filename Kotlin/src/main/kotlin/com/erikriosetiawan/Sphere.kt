package com.erikriosetiawan

import kotlin.math.pow

data class Sphere(var radius: Double? = null) {

    fun volume() = 4 / 3 * Math.PI * radius!!.pow(3.0)

    fun surfaceArea() = 4 * Math.PI * radius!!.pow(2.0)
}