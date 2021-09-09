#include "MyShader.h"
#include "Camera.h"
#include "MyRectangle.h"
XMMATRIX MyRectangle::Projection;

void MyRectangle::Render()
{
	ConstantBuffer cb;

	cb.mWorld = XMMatrixTranspose(transform->GetMatrix());
	cb.mView = XMMatrixTranspose(Camera::GetViewMatrix());
	cb.mProjection = XMMatrixTranspose(Projection);

	context->UpdateSubresource(shader->GetConstantBuffer(), 0, NULL, &cb, 0, 0);

	context->VSSetShader(shader->GetVertexShader(), 0, 0);
	context->VSSetConstantBuffers(0, 1, shader->GetConstantBuffer2());

	context->PSSetShader(shader->GetPixelShader(), 0, 0);
	context->DrawIndexed(6, 0, 0);
}