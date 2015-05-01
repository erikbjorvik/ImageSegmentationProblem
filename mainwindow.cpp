#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <glpk.h>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //this->setStyleSheet("background-color: grey;");
    ui->setupUi(this);
    cv::Mat im = cv::imread("/Users/ErikBjorvik/Documents/DAT105/test/postbil.jpg");
    cv::imshow("window_title", im);


    // create linear programming object
    glp_prob* lp = glp_create_prob();
    glp_set_prob_name(lp, "Testing GLPK");
    glp_set_obj_dir(lp, GLP_MAX); // maximise

    /*
    * Step 1: set up linear program
    */

    // set up objective function: x + y
    glp_add_cols(lp, 2);
    glp_set_col_name(lp, 1, "x");
    glp_set_col_name(lp, 2, "y");
    glp_set_obj_coef(lp, 1, 1.0);
    glp_set_obj_coef(lp, 2, 1.0);

    // set up coefficient matrix
       int index_n[4+1], index_m[4+1];
       double coeff[4+1];
       index_n[1] = 1; index_m[1] = 1; coeff[1] = 15.0;
       index_n[2] = 1; index_m[2] = 2; coeff[2] = 30.0;
       index_n[3] = 2; index_m[3] = 1; coeff[3] = 30.0;
       index_n[4] = 2; index_m[4] = 2; coeff[4] = 20.0;
       glp_add_rows(lp, 2);
       glp_load_matrix(lp,4,index_n,index_m,coeff);

       // set the bounds of our variables
       glp_set_col_bnds(lp, 1, GLP_LO, 30.0, 0.0);
       glp_set_col_bnds(lp, 2, GLP_LO, 15.0, 0.0);
       glp_set_row_bnds(lp, 1, GLP_UP, 0.0, 2400.0);
       glp_set_row_bnds(lp, 2, GLP_UP, 0.0, 2400.0);

       /*
        * Step 2: solve linear program and print result
        */

       glp_simplex(lp, nullptr);
       double  optm = glp_get_obj_val(lp),
       x = glp_get_col_prim(lp,1),
       y = glp_get_col_prim(lp,2);
       printf("\nOptimal = %g\nx = %g\ny = %g\n", optm,x,y);

       // de-allocate linear programming object
       glp_delete_prob(lp);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b1_clicked()
{
     qDebug()<<"Knapp 1 trykket.";
     QPixmap bilde("/Users/ErikBjorvik/Documents/DAT105/test/postbil.jpg");
     ui->label1->setPixmap(bilde);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"Knapp 1 trykket.";
    QPixmap bilde("/Users/ErikBjorvik/Documents/DAT105/test/postbil.jpg");
    ui->label2->setPixmap(bilde);
    ui->label3->setPixmap(bilde);
}
