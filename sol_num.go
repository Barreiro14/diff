package main

import (
        "fmt"
        "gonum.org/v1/plot"
        "gonum.org/v1/plot/plotter"
    "gonum.org/v1/plot/plotutil"
        "gonum.org/v1/plot/vg"
//      "image/color"
        "math"
//    "strconv"
)

func f0(x float64) float64 {
        return 0.5 * (math.Tanh(100.0*(x-0.25)) - math.Tanh(100.0*(x-0.75)))
}

func plotfunction(x, y []float64, ynl []float64, npoint int, filename string) {
        p, err := plot.New()
        if err != nil {
                panic(err)
        }

        p.Title.Text = "Concentración"
        p.X.Label.Text = "$x$"
        p.Y.Label.Text = "$f$"
    p.X.Min = 0.00
    p.X.Max = 1.00
    p.Y.Min = 0.00
    p.Y.Max = 1.00

        pointxy := make(plotter.XYs, npoint)
    pointxynl := make(plotter.XYs, npoint)
        for i := range pointxy {
                pointxy[i].X, pointxy[i].Y = x[i], y[i]
                pointxynl[i].X, pointxynl[i].Y = x[i], ynl[i]
        }

        err = plotutil.AddLinePoints(p, "Lineal", pointxy, "No lineal", pointxynl)
        if err != nil {
                panic(err)
        }

        //save a png file
        if err := p.Save(10*vg.Inch, 10*vg.Inch, filename); err != nil {
                panic(err)
        }
}

//This function compute the first derivative of a funcion in a discrete data array
func deriv3p(y []float64, dx float64, npoint int) [] float64{
    yderiv := make([]float64, npoint)

    for i:=1; i < npoint-1; i++ {
        yderiv[i] = (y[i+1] - y[i-1]) / (2.00*dx)
    }

    yderiv[0] = (-1.50*y[0] + 2.00*y[1] -0.500*y[2])/dx
    yderiv[npoint-1] = (0.500*y[npoint-3] - 2.00*y[npoint-2] + 1.50*y[npoint-1])/dx

    return yderiv
}

func int2str(value int) string {
    return fmt.Sprintf("%04d", value)
}

func main() {
        npoint := 1001 //número de puntos
        xborder := make([]float64, 2)
        xborder[0], xborder[1] = 0.00, 1.00
        h := (xborder[1] - xborder[0]) / float64(npoint) //incremento (dx)
        x := make([]float64, npoint)

        for i := 0; i < npoint; i++ {
                x[i] = h * float64(i)
        }

        //Difusión inicial (t=0)
        y := make([]float64, npoint)
    ynl := make([]float64, npoint)
    ynl2 := make([]float64, npoint)
        for i := 0; i < npoint; i++ {
                y[i] = f0(x[i])
        ynl[i] = f0(x[i])
        }

//      fmt.Println(x, y)

//      plotfunction(x, y, npoint, "init.png")

//    plotfunction(x, deriv3p(y,h,npoint),npoint, "deriv.png");

    //Solución de la difusión lineal
    dt := 0.000001 //incremento del tiempo
    delta := -0.2 //delta = D1/D0
    for i := 0; i < 160001; i++ {
       if i%100 == 0 {
            plotfunction(x, y, ynl, npoint, string("plot")+int2str(i/100)+string(".png"))
       }
        //calculamos la derivada parcial del tiempo como la segunda derivada

        yt := deriv3p(deriv3p(y,h,npoint),h,npoint)
        //calculamos la nueva función y usando la regla del trapecio
        for j:=0; j < npoint; j++{
            y[j] += yt[j]*dt/2.00 //en la regla del trapecio esta área es un tríangulo
        }

        //difusión no lineal

        //el cuadrado de ynl
        for j:=0; j< npoint; j++{
            ynl2[j] = ynl[j]*ynl[j]
        }

        yta := deriv3p(deriv3p(ynl,h,npoint),h,npoint)
        ytb := deriv3p(deriv3p(ynl2,h,npoint),h,npoint)

        for j:=0; j< npoint; j++{
            yt[j] = yta[j] + 0.5*delta*ytb[j] //derivada respecto al tiempo
            ynl[j] += yt[j]*dt/2.00 //en la regla del trapecio esta área es un tríangulo
        }

    }

}


