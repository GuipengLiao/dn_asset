// Simplified Additive Particle shader. Differences from regular Additive Particle one:
// - no Tint color
// - no Smooth particle support
// - no AlphaTest
// - no ColorMask

Shader "Custom/Particles/AdditiveRGB" {
	Properties{
		_MainTex("Particle Texture", 2D) = "white" {}
	}

	Category{
			Tags{ "Queue" = "Transparent" "IgnoreProjector" = "True" "RenderType" = "Transparent" }
			Blend SrcAlpha One
			//AlphaTest Greater .1
			Cull Off Lighting Off ZWrite Off Fog{ Mode Off }

			SubShader{			
				Pass{

					CGPROGRAM
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"

					sampler2D _MainTex;

					struct appdata_t {
						half4 vertex : POSITION;
						fixed4 color : COLOR;
						half2 texcoord : TEXCOORD0;
					};

					struct v2f {
						half4 vertex : SV_POSITION;
						fixed4 color : COLOR;
						half2 texcoord : TEXCOORD0;
					};

					float4 _MainTex_ST;
					v2f vert(appdata_t v)
					{
						v2f o;
						o.vertex = mul(UNITY_MATRIX_MVP, v.vertex);
						o.color = v.color;
						o.texcoord = TRANSFORM_TEX(v.texcoord,_MainTex);
						return o;
					}

					fixed4 frag(v2f i) : SV_Target
					{
						fixed4 color = i.color * tex2D(_MainTex, i.texcoord);
						color.a = (color.r+color.g+color.b)*2;
						return color;//fixed4(color.a,color.a,color.a,1);
					}
						ENDCG
				}
			}
		}
}