package com.erikriosetiawan

import kotlin.math.pow

data class Cube(var side: Double? = null) {

    fun volume() = (side!!).pow(3.0)

    fun surfaceArea() = 6 * (side!!).pow(2.0)
}