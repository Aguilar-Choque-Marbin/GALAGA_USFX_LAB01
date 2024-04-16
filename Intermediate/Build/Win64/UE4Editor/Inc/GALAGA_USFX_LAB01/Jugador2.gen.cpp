// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GALAGA_USFX_LAB01/Jugador2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJugador2() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AJugador2_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AJugador2();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_GALAGA_USFX_LAB01();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AJugador2::StaticRegisterNativesAJugador2()
	{
	}
	UClass* Z_Construct_UClass_AJugador2_NoRegister()
	{
		return AJugador2::StaticClass();
	}
	struct Z_Construct_UClass_AJugador2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaNave2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaNave2;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AJugador2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_GALAGA_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJugador2_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Jugador2.h" },
		{ "ModuleRelativePath", "Jugador2.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJugador2_Statics::NewProp_MallaNave2_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Jugador2.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJugador2_Statics::NewProp_MallaNave2 = { "MallaNave2", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AJugador2, MallaNave2), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AJugador2_Statics::NewProp_MallaNave2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AJugador2_Statics::NewProp_MallaNave2_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJugador2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJugador2_Statics::NewProp_MallaNave2,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AJugador2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJugador2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AJugador2_Statics::ClassParams = {
		&AJugador2::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AJugador2_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AJugador2_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AJugador2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AJugador2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AJugador2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AJugador2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJugador2, 808818425);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AJugador2>()
	{
		return AJugador2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJugador2(Z_Construct_UClass_AJugador2, &AJugador2::StaticClass, TEXT("/Script/GALAGA_USFX_LAB01"), TEXT("AJugador2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJugador2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
