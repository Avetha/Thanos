using UnityEngine;
using System.Collections;

public class HexGridLayout : MonoBehaviour
{
    public Vector3 v3Center = Vector3.zero;
    public float objDistance = 0.75f;  // Distance apart objects are apart on a row
    public int rows = 8;
    public int cols = 8;

    private float rowDist;
    private float rowStart;
    private Vector3 v3Pos;
    private Vector3 v3Scale = new Vector3(0.2f, 0.2f, 0.2f);

    void Start()
    {
        // Distance the rows are apart Sqrt(objDist^2 - (objDist/2)^2)
        float fT = ((objDistance * objDistance) - ((objDistance * objDistance * 0.25f)));
        rowDist = Mathf.Sqrt((objDistance * objDistance) - ((objDistance * objDistance * 0.25f)));
        rowStart = -(cols * objDistance / 2.0f - 0.25f * objDistance);
        v3Pos = new Vector3(rowStart, rows * rowDist / 2.0f, 0.0f);

        for (int i = 0; i < rows; i++)
        {
            if ((i % 2) == 1)
                v3Pos.x -= objDistance / 2.0f;
            for (int j = 0; j < cols; j++)
            {
                GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                go.transform.position = v3Pos + v3Center;
                go.transform.localScale = v3Scale;
                v3Pos.x += objDistance;
            }
            v3Pos.x = rowStart;
            v3Pos.y -= rowDist;
        }

    }
}