//Based on the example in the book of shader
//https://thebookofshaders.com/07/

#version 120

uniform vec2 u_resolution;
uniform float u_time;

void main( void ) {
    
    vec2 st = gl_FragCoord.xy / u_resolution.y;
    
    st = st *2.-1.;
    
    float d =length(abs(cos(st))-sin(u_time)); //4 sections
    
    vec3 color = vec3(st.x, st.y, 1.0);
    vec3 shape = vec3(fract(d*sin(u_time)*80));
    
//    gl_FragColor = vec4(vec3(fract(d*sin(u_time)*80)),1.0);
    gl_FragColor = vec4(mix(color,shape,0.2),1.0);
}