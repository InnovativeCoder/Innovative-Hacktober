package com.erikriosetiawan

fun main() {
    greetings("Welcome to My Program, Here You Calculate The Volume of Geometry")
    val choice = chooseGeometry()
    geometryChoosen(choice)
}

private fun greetings(message: String?) {
    println("========== Geometry Calculator ==========")
    println(message)
    println("=========================================")
}

private fun chooseGeometry(): Int? {
    println("Available Geometry")
    print("1. Cube\n")
    print("2. Cuboids\n")
    print("3. Triangular Prism\n")
    print("4. Square Pyramid\n")
    print("5. Triangular Pyramid\n")
    print("6. Cylinder\n")
    print("7. Cone\n")
    print("8. Sphere\n")
    print("Enter your choice: ")
    return readLine()!!.toInt()
}

private fun geometryChoosen(choice: Int?) {
    when (choice) {
        1 -> {
            val myCube = Cube()
            print("Please enter the side: ")
            myCube.side = readLine()!!.toDouble()
            printResult("Cube", myCube.volume(), myCube.surfaceArea())
        }

        2 -> {
            val myCuboids = Cuboids()
            print("Please enter the length: ")
            myCuboids.length = readLine()!!.toDouble()
            print("Please enter the width: ")
            myCuboids.width = readLine()!!.toDouble()
            print("Please enter the height: ")
            myCuboids.height = readLine()!!.toDouble()
            printResult("Cuboid", myCuboids.volume(), myCuboids.surfaceArea())
        }

        3 -> {
            val myTriangularPrism = TriangularPrism()
            print("Please enter the pedestral area: ")
            myTriangularPrism.pedestralArea = readLine()!!.toDouble()
            print("Please enter the height: ")
            myTriangularPrism.height = readLine()!!.toDouble()
            print("Please enter the around area: ")
            myTriangularPrism.aroundArea = readLine()!!.toDouble()
            printResult("Triangular Prism", myTriangularPrism.volume(), myTriangularPrism.surfaceArea())
        }

        4 -> {
            val mySquarePyramid = SquarePyramid()
            print("Please enter the pedestral area: ")
            mySquarePyramid.pedestralArea = readLine()!!.toDouble()
            print("Please enter the height: ")
            mySquarePyramid.height = readLine()!!.toDouble()
            print("Please enter the covering area: ")
            mySquarePyramid.coveringArea = readLine()!!.toDouble()
            printResult("Square Pyramid", mySquarePyramid.volume(), mySquarePyramid.surfaceArea())
        }

        5 -> {
            val myTriangularPyramid = TriangularPyramid()
            print("Please enter the pedestral area: ")
            myTriangularPyramid.pedestralArea = readLine()!!.toDouble()
            print("Please enter the height: ")
            myTriangularPyramid.height = readLine()!!.toDouble()
            print("Please enter the covering area: ")
            myTriangularPyramid.coveringArea = readLine()!!.toDouble()
            printResult("Triangular Pyramid", myTriangularPyramid.volume(), myTriangularPyramid.surfaceArea())
        }

        6 -> {
            val myCylinder = Cylinder()
            print("Please enter the pedestral area: ")
            myCylinder.pedestralArea = readLine()!!.toDouble()
            print("Please enter the height: ")
            myCylinder.height = readLine()!!.toDouble()
            print("Please enter the around area: ")
            myCylinder.aroundArea = readLine()!!.toDouble()
            printResult("Cylinder", myCylinder.volume(), myCylinder.surfaceArea())
        }

        7 -> {
            val myCone = Cone()
            print("Please enter the radius: ")
            myCone.radius = readLine()!!.toDouble()
            print("Please enter the height: ")
            myCone.height = readLine()!!.toDouble()
            print("Please enter the side: ")
            myCone.side = readLine()!!.toDouble()
            printResult("Cone", myCone.volume(), myCone.surfaceArea())
        }

        8 -> {
            val mySphere = Sphere()
            print("Please enter the radius: ")
            mySphere.radius = readLine()!!.toDouble()
            printResult("Sphere", mySphere.volume(), mySphere.surfaceArea())
        }

        else -> {
            print("Sorry, you choose the unvalid number, please try again")
        }
    }
}

private fun printResult(geometryName: String?, geometryVolume: Double?, geometrySurfaceArea: Double?) {
    println("The volume of $geometryName is $geometryVolume\nThe surface area of $geometryName is $geometrySurfaceArea")
}