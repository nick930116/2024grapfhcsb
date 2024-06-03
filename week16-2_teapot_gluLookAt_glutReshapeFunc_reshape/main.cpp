#include <GL/glut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

void reshape(int w, int h){
    float ar = w/(float)h;///aspect ratio 長寬比
    glViewport(0, 0, w, h);///設定可以看到的範圍,全看到
    glMatrixMode(GL_PROJECTION);///現在要設定成Projection矩陣
    glLoadIdentity();///最原始單位矩陣I
    gluPerspective(60, ar, 0.1, 100);///透視投影的參數
    glMatrixMode(GL_MODELVIEW);///現在要切換回 model view 矩陣(畫圖的T,R,S的)
    glLoadIdentity();
    gluLookAt(0, 0, -3,  0, 0, 0,  0, 1, 0);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800, 800);///設定我們的視窗大小
    glutCreateWindow("week16-2");

    glutReshapeFunc(reshape);///新加這行, 註冊[改變長寬時], 要呼叫誰
    glutDisplayFunc(display);

    glutMainLoop();
}
