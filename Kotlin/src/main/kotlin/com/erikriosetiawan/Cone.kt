package com.erikriosetiawan

import kotlin.math.pow

data class Cone(var radius: Double? = null, var height: Double? = null, var side: Double? = null) {

    fun volume() = 1.0 / 3.0 * Math.PI * radius!!.pow(2.0) * height!!

    fun surfaceArea() = (Math.PI * radius!!.pow(2.0)) + (Math.PI * radius!! * side!!)
}