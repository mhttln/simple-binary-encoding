/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _UK_CO_REAL_LOGIC_SBE_IR_GENERATED_FRAMECODEC_H_
#define _UK_CO_REAL_LOGIC_SBE_IR_GENERATED_FRAMECODEC_H_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#if __cplusplus >= 201103L
#  include <cstdint>
#  include <functional>
#  include <string>
#endif

#include <sbe/sbe.h>

#include "ByteOrderCodec.h"
#include "SignalCodec.h"
#include "PresenceCodec.h"
#include "PrimitiveTypeCodec.h"
#include "VarDataEncoding.h"

using namespace sbe;

namespace uk_co_real_logic_sbe_ir_generated {

class FrameCodec
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    inline void reset(char *buffer, const int offset, const int bufferLength, const int actingBlockLength, const int actingVersion)
    {
        buffer_ = buffer;
        offset_ = offset;
        bufferLength_ = bufferLength;
        actingBlockLength_ = actingBlockLength;
        actingVersion_ = actingVersion;
        positionPtr_ = &position_;
        position(offset + actingBlockLength_);
    }

public:

    FrameCodec(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    FrameCodec(char *buffer, const int bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    FrameCodec(char *buffer, const int bufferLength, const int actingBlockLength, const int actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    FrameCodec(const FrameCodec& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
    }

#if __cplusplus >= 201103L
    FrameCodec(FrameCodec&& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
    }

    FrameCodec& operator=(FrameCodec&& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
        return *this;
    }

#endif

    FrameCodec& operator=(const FrameCodec& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
        return *this;
    }

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)12;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)1;
    }

    static const sbe_uint16_t sbeSchemaId(void)
    {
        return (sbe_uint16_t)1;
    }

    static const sbe_uint16_t sbeSchemaVersion(void)
    {
        return (sbe_uint16_t)0;
    }

    static const char *sbeSemanticType(void)
    {
        return "";
    }

    sbe_uint64_t offset(void) const
    {
        return offset_;
    }

    FrameCodec &wrapForEncode(char *buffer, const int offset, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    FrameCodec &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, actingBlockLength, actingVersion);
        return *this;
    }

    sbe_uint64_t position(void) const
    {
        return position_;
    }

    void position(const int position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > bufferLength_), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        position_ = position;
    }

    int size(void) const
    {
        return position() - offset_;
    }

    char *buffer(void)
    {
        return buffer_;
    }

    int actingVersion(void) const
    {
        return actingVersion_;
    }

    static const int irIdId(void)
    {
        return 1;
    }

    static const int irIdSinceVersion(void)
    {
         return 0;
    }

    bool irIdInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *irIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_int32_t irIdNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static const sbe_int32_t irIdMinValue()
    {
        return -2147483647;
    }

    static const sbe_int32_t irIdMaxValue()
    {
        return 2147483647;
    }

    sbe_int32_t irId(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 0)));
    }

    FrameCodec &irId(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const int irVersionId(void)
    {
        return 2;
    }

    static const int irVersionSinceVersion(void)
    {
         return 0;
    }

    bool irVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *irVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_int32_t irVersionNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static const sbe_int32_t irVersionMinValue()
    {
        return -2147483647;
    }

    static const sbe_int32_t irVersionMaxValue()
    {
        return 2147483647;
    }

    sbe_int32_t irVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 4)));
    }

    FrameCodec &irVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 4)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const int schemaVersionId(void)
    {
        return 3;
    }

    static const int schemaVersionSinceVersion(void)
    {
         return 0;
    }

    bool schemaVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *schemaVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_int32_t schemaVersionNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static const sbe_int32_t schemaVersionMinValue()
    {
        return -2147483647;
    }

    static const sbe_int32_t schemaVersionMaxValue()
    {
        return 2147483647;
    }

    sbe_int32_t schemaVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 8)));
    }

    FrameCodec &schemaVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const char *packageNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const char *packageNameCharacterEncoding()
    {
        return "UTF-8";
    }

    static const int packageNameSinceVersion(void)
    {
         return 0;
    }

    bool packageNameInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static const int packageNameId(void)
    {
        return 4;
    }


    static const int packageNameHeaderSize()
    {
        return 1;
    }

    sbe_int64_t packageNameLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *packageName(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getPackageName(char *dst, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)dataLength);
        ::memcpy(dst, buffer_ + pos, bytesToCopy);
        return bytesToCopy;
    }

    int putPackageName(const char *src, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)length);
        ::memcpy(buffer_ + pos, src, length);
        return length;
    }

    const std::string getPackageNameAsString()
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        sbe_uint64_t pos = position();
        const std::string result(buffer_ + pos, dataLength);
        position(position() + (sbe_uint64_t)dataLength);
        return std::move(result);
    }

    FrameCodec &putPackageName(const std::string& str)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)str.length());
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)str.length());
        ::memcpy(buffer_ + pos, str.c_str(), str.length());
        return *this;
    }

    static const char *namespaceNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const char *namespaceNameCharacterEncoding()
    {
        return "UTF-8";
    }

    static const int namespaceNameSinceVersion(void)
    {
         return 0;
    }

    bool namespaceNameInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static const int namespaceNameId(void)
    {
        return 5;
    }


    static const int namespaceNameHeaderSize()
    {
        return 1;
    }

    sbe_int64_t namespaceNameLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *namespaceName(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getNamespaceName(char *dst, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)dataLength);
        ::memcpy(dst, buffer_ + pos, bytesToCopy);
        return bytesToCopy;
    }

    int putNamespaceName(const char *src, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)length);
        ::memcpy(buffer_ + pos, src, length);
        return length;
    }

    const std::string getNamespaceNameAsString()
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        sbe_uint64_t pos = position();
        const std::string result(buffer_ + pos, dataLength);
        position(position() + (sbe_uint64_t)dataLength);
        return std::move(result);
    }

    FrameCodec &putNamespaceName(const std::string& str)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)str.length());
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)str.length());
        ::memcpy(buffer_ + pos, str.c_str(), str.length());
        return *this;
    }

    static const char *semanticVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const char *semanticVersionCharacterEncoding()
    {
        return "UTF-8";
    }

    static const int semanticVersionSinceVersion(void)
    {
         return 0;
    }

    bool semanticVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static const int semanticVersionId(void)
    {
        return 6;
    }


    static const int semanticVersionHeaderSize()
    {
        return 1;
    }

    sbe_int64_t semanticVersionLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *semanticVersion(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getSemanticVersion(char *dst, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)dataLength);
        ::memcpy(dst, buffer_ + pos, bytesToCopy);
        return bytesToCopy;
    }

    int putSemanticVersion(const char *src, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)length);
        ::memcpy(buffer_ + pos, src, length);
        return length;
    }

    const std::string getSemanticVersionAsString()
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        sbe_uint64_t pos = position();
        const std::string result(buffer_ + pos, dataLength);
        position(position() + (sbe_uint64_t)dataLength);
        return std::move(result);
    }

    FrameCodec &putSemanticVersion(const std::string& str)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)str.length());
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)str.length());
        ::memcpy(buffer_ + pos, str.c_str(), str.length());
        return *this;
    }
};
}
#endif