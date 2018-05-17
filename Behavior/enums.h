#ifndef ENUMS_H
#define ENUMS_H

enum Style
{
    BezierBerstein,
    BezierDeCasteljau,
    BezierMatrix,
    BSpline,
    HermiteClamped,
    HermiteNatural
};

enum NodeType
{
    InterpPoints,
    PseudoPoints,
    ControlPoints,
    CurvePoints
};

#endif // ENUMS_H
