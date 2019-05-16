#include <gui/screenauth_screen/ScreenAuthView.hpp>
#include <touchgfx/Color.hpp>

ScreenAuthView::ScreenAuthView()
{

}

void ScreenAuthView::setupScreen()
{
  ScreenAuthViewBase::setupScreen();
}

void ScreenAuthView::tearDownScreen()
{
    ScreenAuthViewBase::tearDownScreen();
}
void ScreenAuthView::updateBar(int val)
{
  boxProgress_Demande_Code.setValue(val);
}
void ScreenAuthView::updateAlphaTXT(int val){
  TXT_Codes.setAlpha(val);
}
void ScreenAuthView::updateWildcardCode(char val, int auth)
{
	if(auth==0){
		Unicode::snprintf(TXT_Code_Entre1Buffer,5,"%c",val);
  		TXT_Code_Entre1.invalidate();
  		Unicode::snprintf(TXT_Code_Entre2Buffer,5,"%c",'X');
  		TXT_Code_Entre2.invalidate();
  		Unicode::snprintf(TXT_Code_Entre3Buffer,5,"%c",'X');
  		TXT_Code_Entre3.invalidate();
  		Unicode::snprintf(TXT_Code_Entre4Buffer,5,"%c",'X');
  		TXT_Code_Entre4.invalidate();
	}
	if(auth==1){
		Unicode::snprintf(TXT_Code_Entre2Buffer,5,"%c",val);
  		TXT_Code_Entre2.invalidate();
  		Unicode::snprintf(TXT_Code_Entre1Buffer,5,"%c",'X');
  		TXT_Code_Entre1.invalidate();
  		Unicode::snprintf(TXT_Code_Entre3Buffer,5,"%c",'X');
  		TXT_Code_Entre3.invalidate();
  		Unicode::snprintf(TXT_Code_Entre4Buffer,5,"%c",'X');
  		TXT_Code_Entre4.invalidate();
	}
	if(auth==2){
		Unicode::snprintf(TXT_Code_Entre3Buffer,5,"%c",val);
  		TXT_Code_Entre3.invalidate();
  		Unicode::snprintf(TXT_Code_Entre1Buffer,5,"%c",'X');
  		TXT_Code_Entre1.invalidate();
  		Unicode::snprintf(TXT_Code_Entre2Buffer,5,"%c",'X');
  		TXT_Code_Entre2.invalidate();
  		Unicode::snprintf(TXT_Code_Entre4Buffer,5,"%c",'X');
  		TXT_Code_Entre4.invalidate();
	}
	if(auth==3){
		Unicode::snprintf(TXT_Code_Entre4Buffer,5,"%c",val);
  		TXT_Code_Entre4.invalidate();
  		Unicode::snprintf(TXT_Code_Entre1Buffer,5,"%c",'X');
  		TXT_Code_Entre1.invalidate();
  		Unicode::snprintf(TXT_Code_Entre2Buffer,5,"%c",'X');
  		TXT_Code_Entre2.invalidate();
  		Unicode::snprintf(TXT_Code_Entre3Buffer,5,"%c",'X');
  		TXT_Code_Entre3.invalidate();
	}
}
void ScreenAuthView::updateColorBar(uint8_t R, uint8_t G, uint8_t B)
{
  boxProgress_Demande_Code.setColor(Color::getColorFrom24BitRGB(R, G, B));
}