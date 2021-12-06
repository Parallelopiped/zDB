//
// Created by NaturalVStudio on 2021/12/2.
//

#include "Exception.h"
#include <iostream>

/**
 * �����쳣���쳣�����ʽ��
 * ʹ��int32������Ϊ�쳣��ţ���ǰ��λ�����쳣���ͺţ�����λΪ�쳣���
 * * * * * * *  *  *  *  * * * * * *
 * ����0000�������ֶΣ�ϵͳ�����쳣
 * ����0001�������﷨�������
 * ����0002��tableԼ�����
 *
 * @return ExcpList
 */
std::unordered_map<int32_t, std::string> Exception::CreateExcpList() {
    std::unordered_map<int32_t , std::string> temp;

    temp[0x00010001] = "zDB�쳣[0x00010001]: ���ÿհ��ַ��ָ�SQL���";
    temp[0x00010002] = "zDB�쳣[0x00010002]: �Ƿ�SQL��䣬����";
    temp[0x00010003] = "zDB�쳣[0x00010003]: ������create��������ѡ�table, index, view";
    temp[0x00010004] = "zDB�쳣[0x00010004]: insert�����������";

    temp[0x00020001] = "zDB�쳣[0x00020001]: �Ѵ��ڸñ�";

    return temp;
}

void Exception::RaiseException(int32_t ExcpCode) {
    std::cout << exceptionList[ExcpCode] << std::endl;
}
std::unordered_map<int32_t , std::string> Exception::exceptionList = Exception::CreateExcpList();
